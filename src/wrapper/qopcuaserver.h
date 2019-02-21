#ifndef QOPCUASERVER_H
#define QOPCUASERVER_H

#include <QOpcUaTypesConverter>
#include <type_traits>

#include <QOpcUaBaseObject>
#include <QOpcUaBaseVariable>

class QOpcUaFolderObject;

class QOpcUaServer : public QObject
{
	Q_OBJECT

friend class QOpcUaServerNode;
friend class QOpcUaBaseVariable;

public:
    explicit QOpcUaServer(QObject *parent = 0);

	void start();

	// register type in order to assign it a typeNodeId
	template<typename T>
	void registerType();

	// create instance of a given type
	template<typename T>
	T* createInstance(QOpcUaServerNode * parentNode, const QString &strBrowseName = "");

	QOpcUaFolderObject * get_objectsFolder();
	

signals:

public slots:

private:
	UA_Server * m_server;

	QOpcUaFolderObject * m_pobjectsFolder;

	static UA_NodeId getReferenceTypeId(const QString &strParentClassName, const QString &strChildClassName);
};

template<typename T>
inline void QOpcUaServer::registerType()
{
	// TODO : T::SetTypeNodeId( ... );

	QOpcUaNodeFactory<T>::SetTypeNodeId(UA_NODEID_NULL);

	/*
	if (T::staticMetaObject.inherits(&QOpcUaAbstractObject::staticMetaObject))
	{
		UA_Server_addObjectTypeNode
	}
	else if (T::staticMetaObject.inherits(&QOpcUaAbstractVariable::staticMetaObject))
	{
		UA_Server_addVariableTypeNode
	}
	*/
}

template<typename T>
inline T * QOpcUaServer::createInstance(QOpcUaServerNode * parentNode, const QString &strBrowseName/* = ""*/)
{
	Q_ASSERT(!UA_NodeId_isNull(&parentNode->m_nodeId));
	// try to get typeNodeId, if null, then register it
	UA_NodeId typeNodeId = QOpcUaNodeFactory<T>::GetTypeNodeId();
	if (UA_NodeId_isNull(&typeNodeId))
	{
		this->registerType<T>();
		typeNodeId = QOpcUaNodeFactory<T>::GetTypeNodeId();
	}
	Q_ASSERT(!UA_NodeId_isNull(&typeNodeId));
	// instantiate C++ object or variable
	T *  childNode = new T(parentNode);

	// adapt parent relation with child according to parent type
	UA_NodeId referenceTypeId = QOpcUaServer::getReferenceTypeId(parentNode->metaObject()->className(), 
		                                                         childNode->metaObject()->className());

	// set qualified name, default is class name
	UA_QualifiedName browseName;
	browseName.namespaceIndex = 1;
	browseName.name           = QOpcUaTypesConverter::uaStringFromQString(strBrowseName.isEmpty() ? 
		                                                                  QString(T::staticMetaObject.className()) : 
		                                                                  strBrowseName);

	// check if object or variable
	// NOTE : a type is considered to inherit itself (http://doc.qt.io/qt-5/qmetaobject.html#inherits)
	if (T::staticMetaObject.inherits(&QOpcUaBaseObject::staticMetaObject))
	{
		// add to OpcUa
		UA_ObjectAttributes oAttr = UA_ObjectAttributes_default;
		UA_Server_addObjectNode(m_server, 
                                UA_NODEID_NULL,       // requested nodeId
                                parentNode->m_nodeId, // parent
                                referenceTypeId,      // parent relation with child
                                browseName,
                                typeNodeId,
                                oAttr, 
                                (void*)childNode,      // set new instance as context
                                &childNode->m_nodeId); // set new nodeId to new instance
	}
	else if (T::staticMetaObject.inherits(&QOpcUaBaseVariable::staticMetaObject))
	{
		UA_VariableAttributes vAttr = UA_VariableAttributes_default;
		UA_Server_addVariableNode(m_server,
                                  UA_NODEID_NULL,       // requested nodeId
                                  parentNode->m_nodeId, // parent
                                  referenceTypeId,      // parent relation with child
                                  browseName,
                                  typeNodeId, 
                                  vAttr, 
                                  (void*)childNode,      // set new instance as context
                                  &childNode->m_nodeId); // set new nodeId to new instance
	}
	else
	{
		Q_ASSERT_X(false, "QOpcUaServer::createInstance", "Unsopported type.");
		delete childNode;
		return nullptr;
	}

	return childNode;
}


#endif // QOPCUASERVER_H
