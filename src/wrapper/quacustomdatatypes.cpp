#include "quacustomdatatypes.h"

#include <QUaTypesConverter>

#include<QMetaEnum>

QHash<QString, QMetaType::Type> QUaDataType::m_custTypesByName = {
	{QString("Bool")                      , QMetaType::Bool                  },
	{QString("Char")                      , QMetaType::Char                  },
	{QString("SChar")                     , QMetaType::SChar                 },
	{QString("UChar")                     , QMetaType::UChar                 },
	{QString("Short")                     , QMetaType::Short                 },
	{QString("UShort")                    , QMetaType::UShort                },
	{QString("Int")                       , QMetaType::Int                   },
	{QString("UInt")                      , QMetaType::UInt                  },
	{QString("Long")                      , QMetaType::Long                  },
	{QString("LongLong")                  , QMetaType::LongLong              },
	{QString("ULong")                     , QMetaType::ULong                 },
	{QString("ULongLong")                 , QMetaType::ULongLong             },
	{QString("Float")                     , QMetaType::Float                 },
	{QString("Double")                    , QMetaType::Double                },
	{QString("QString")                   , QMetaType::QString               },
	{QString("QDateTime")                 , QMetaType::QDateTime             },
	{QString("QUuid")                     , QMetaType::QUuid                 },
	{QString("QByteArray")                , QMetaType::QByteArray            },
	{QString("UnknownType")               , QMetaType::UnknownType           },
	{QString("QUaNodeId")                 , QMetaType_NodeId                 },
	{QString("QUaStatusCode")             , QMetaType_StatusCode             },
	{QString("QUaQualifiedName")          , QMetaType_QualifiedName          },
	{QString("QUaLocalizedText")          , QMetaType_LocalizedText          },
	{QString("QTimeZone")                 , QMetaType_TimeZone               },
	{QString("QImage")                    , QMetaType_Image                  },
	{QString("QUaChangeStructureDataType"), QMetaType_ChangeStructureDataType}
};

QHash<UA_NodeId, QMetaType::Type> QUaDataType::m_custTypesByNodeId = {
	{UA_NODEID_NUMERIC(0, UA_NS0ID_BOOLEAN)                     , QMetaType::Bool                  },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_SBYTE)                       , QMetaType::Char                  },
	//{UA_NODEID_NUMERIC(0, UA_NS0ID_SBYTE)                       , QMetaType::SChar                 },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_BYTE)                        , QMetaType::UChar                 },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_INT16)                       , QMetaType::Short                 },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_UINT16)                      , QMetaType::UShort                },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_INT32)                       , QMetaType::Int                   },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_UINT32)                      , QMetaType::UInt                  },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_INT64)                       , QMetaType::Long                  },
	//{UA_NODEID_NUMERIC(0, UA_NS0ID_INT64)                       , QMetaType::LongLong              },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_UINT64)                      , QMetaType::ULong                 },
	//{UA_NODEID_NUMERIC(0, UA_NS0ID_UINT64)                      , QMetaType::ULongLong             },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_FLOAT)                       , QMetaType::Float                 },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_DOUBLE)                      , QMetaType::Double                },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_STRING)                      , QMetaType::QString               },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_DATETIME)                    , QMetaType::QDateTime             },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_UTCTIME)                     , QMetaType::QDateTime             },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_GUID)                        , QMetaType::QUuid                 },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_BYTESTRING)                  , QMetaType::QByteArray            },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATATYPE)                , QMetaType::UnknownType           },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_NODEID)                      , QMetaType_NodeId                 },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_STATUSCODE)                  , QMetaType_StatusCode             },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_QUALIFIEDNAME)               , QMetaType_QualifiedName          },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_LOCALIZEDTEXT)               , QMetaType_LocalizedText          },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_TIMEZONEDATATYPE)            , QMetaType_TimeZone               },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_IMAGE)                       , QMetaType_Image                  },
	{UA_NODEID_NUMERIC(0, UA_NS0ID_MODELCHANGESTRUCTUREDATATYPE), QMetaType_ChangeStructureDataType}
};

QHash<int, QMetaType::Type> QUaDataType::m_custTypesByTypeIndex = {
	{UA_TYPES_BOOLEAN                     , QMetaType::Bool                  },
	{UA_TYPES_SBYTE                       , QMetaType::Char                  },
	//{UA_TYPES_SBYTE                       , QMetaType::SChar                 },
	{UA_TYPES_BYTE                        , QMetaType::UChar                 },
	{UA_TYPES_INT16                       , QMetaType::Short                 },
	{UA_TYPES_UINT16                      , QMetaType::UShort                },
	{UA_TYPES_INT32                       , QMetaType::Int                   },
	{UA_TYPES_UINT32                      , QMetaType::UInt                  },
	{UA_TYPES_INT64                       , QMetaType::Long                  },
	//{UA_TYPES_INT64                       , QMetaType::LongLong              },
	{UA_TYPES_UINT64                      , QMetaType::ULong                 },
	//{UA_TYPES_UINT64                      , QMetaType::ULongLong             },
	{UA_TYPES_FLOAT                       , QMetaType::Float                 },
	{UA_TYPES_DOUBLE                      , QMetaType::Double                },
	{UA_TYPES_STRING                      , QMetaType::QString               },
	{UA_TYPES_DATETIME                    , QMetaType::QDateTime             },
	{UA_TYPES_GUID                        , QMetaType::QUuid                 },
	{UA_TYPES_BYTESTRING                  , QMetaType::QByteArray            },
	{UA_TYPES_VARIANT                     , QMetaType::UnknownType           },
	{UA_TYPES_NODEID                      , QMetaType_NodeId                 },
	{UA_TYPES_STATUSCODE                  , QMetaType_StatusCode             },
	{UA_TYPES_QUALIFIEDNAME               , QMetaType_QualifiedName          },
	{UA_TYPES_LOCALIZEDTEXT               , QMetaType_LocalizedText          },
	{UA_TYPES_TIMEZONEDATATYPE            , QMetaType_TimeZone               },
	{UA_TYPES_IMAGEPNG                    , QMetaType_Image                  },
	{UA_TYPES_MODELCHANGESTRUCTUREDATATYPE, QMetaType_ChangeStructureDataType}
};

QHash<QMetaType::Type, QUaDataType::TypeData> QUaDataType::m_custTypesByType = {
	{ QMetaType::Bool                   , {QString("Bool")                       , UA_NODEID_NUMERIC(0, UA_NS0ID_BOOLEAN)                     , &UA_TYPES[UA_TYPES_BOOLEAN                     ]} },
	{ QMetaType::Char                   , {QString("Char")                       , UA_NODEID_NUMERIC(0, UA_NS0ID_SBYTE)                       , &UA_TYPES[UA_TYPES_SBYTE                       ]} },
	{ QMetaType::SChar                  , {QString("SChar")                      , UA_NODEID_NUMERIC(0, UA_NS0ID_SBYTE)                       , &UA_TYPES[UA_TYPES_SBYTE                       ]} },
	{ QMetaType::UChar                  , {QString("UChar")                      , UA_NODEID_NUMERIC(0, UA_NS0ID_BYTE)                        , &UA_TYPES[UA_TYPES_BYTE                        ]} },
	{ QMetaType::Short                  , {QString("Short")                      , UA_NODEID_NUMERIC(0, UA_NS0ID_INT16)                       , &UA_TYPES[UA_TYPES_INT16                       ]} },
	{ QMetaType::UShort                 , {QString("UShort")                     , UA_NODEID_NUMERIC(0, UA_NS0ID_UINT16)                      , &UA_TYPES[UA_TYPES_UINT16                      ]} },
	{ QMetaType::Int                    , {QString("Int")                        , UA_NODEID_NUMERIC(0, UA_NS0ID_INT32)                       , &UA_TYPES[UA_TYPES_INT32                       ]} },
	{ QMetaType::UInt                   , {QString("UInt")                       , UA_NODEID_NUMERIC(0, UA_NS0ID_UINT32)                      , &UA_TYPES[UA_TYPES_UINT32                      ]} },
	{ QMetaType::Long                   , {QString("Long")                       , UA_NODEID_NUMERIC(0, UA_NS0ID_INT64)                       , &UA_TYPES[UA_TYPES_INT64                       ]} },
	{ QMetaType::LongLong               , {QString("LongLong")                   , UA_NODEID_NUMERIC(0, UA_NS0ID_INT64)                       , &UA_TYPES[UA_TYPES_INT64                       ]} },
	{ QMetaType::ULong                  , {QString("ULong")                      , UA_NODEID_NUMERIC(0, UA_NS0ID_UINT64)                      , &UA_TYPES[UA_TYPES_UINT64                      ]} },
	{ QMetaType::ULongLong              , {QString("ULongLong")                  , UA_NODEID_NUMERIC(0, UA_NS0ID_UINT64)                      , &UA_TYPES[UA_TYPES_UINT64                      ]} },
	{ QMetaType::Float                  , {QString("Float")                      , UA_NODEID_NUMERIC(0, UA_NS0ID_FLOAT)                       , &UA_TYPES[UA_TYPES_FLOAT                       ]} },
	{ QMetaType::Double                 , {QString("Double")                     , UA_NODEID_NUMERIC(0, UA_NS0ID_DOUBLE)                      , &UA_TYPES[UA_TYPES_DOUBLE                      ]} },
	{ QMetaType::QString                , {QString("QString")                    , UA_NODEID_NUMERIC(0, UA_NS0ID_STRING)                      , &UA_TYPES[UA_TYPES_STRING                      ]} },
	{ QMetaType::QDateTime              , {QString("QDateTime")                  , UA_NODEID_NUMERIC(0, UA_NS0ID_DATETIME)                    , &UA_TYPES[UA_TYPES_DATETIME                    ]} },
	{ QMetaType::QUuid                  , {QString("QUuid")                      , UA_NODEID_NUMERIC(0, UA_NS0ID_GUID)                        , &UA_TYPES[UA_TYPES_GUID                        ]} },
	{ QMetaType::QByteArray             , {QString("QByteArray")                 , UA_NODEID_NUMERIC(0, UA_NS0ID_BYTESTRING)                  , &UA_TYPES[UA_TYPES_BYTESTRING                  ]} },
	{ QMetaType::UnknownType            , {QString("UnknownType")                , UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATATYPE)                , &UA_TYPES[UA_TYPES_VARIANT                     ]} },
	{ QMetaType_NodeId                  , {QString("QUaNodeId")                  , UA_NODEID_NUMERIC(0, UA_NS0ID_NODEID)                      , &UA_TYPES[UA_TYPES_NODEID                      ]} },
	{ QMetaType_StatusCode              , {QString("QUaStatusCode")              , UA_NODEID_NUMERIC(0, UA_NS0ID_STATUSCODE)                  , &UA_TYPES[UA_TYPES_STATUSCODE                  ]} },
	{ QMetaType_QualifiedName           , {QString("QUaQualifiedName")           , UA_NODEID_NUMERIC(0, UA_NS0ID_QUALIFIEDNAME)               , &UA_TYPES[UA_TYPES_QUALIFIEDNAME               ]} },
	{ QMetaType_LocalizedText           , {QString("QUaLocalizedText")           , UA_NODEID_NUMERIC(0, UA_NS0ID_LOCALIZEDTEXT)               , &UA_TYPES[UA_TYPES_LOCALIZEDTEXT               ]} },
	{ QMetaType_TimeZone                , {QString("QTimeZone")                  , UA_NODEID_NUMERIC(0, UA_NS0ID_TIMEZONEDATATYPE)            , &UA_TYPES[UA_TYPES_TIMEZONEDATATYPE            ]} },
	{ QMetaType_Image                   , {QString("QImage")                     , UA_NODEID_NUMERIC(0, UA_NS0ID_IMAGE)                       , &UA_TYPES[UA_TYPES_IMAGEPNG                    ]} },
	{ QMetaType_ChangeStructureDataType , {QString("QUaChangeStructureDataType") , UA_NODEID_NUMERIC(0, UA_NS0ID_MODELCHANGESTRUCTUREDATATYPE), &UA_TYPES[UA_TYPES_MODELCHANGESTRUCTUREDATATYPE]} }
};

QUaDataType::QUaDataType()
{
	m_type = QMetaType::UnknownType;
}

QUaDataType::QUaDataType(const QMetaType::Type& metaType)
{
	m_type = metaType;
}

QUaDataType::QUaDataType(const QString& strType)
{
	*this = strType;
}

QUaDataType::operator QMetaType::Type() const
{
	return m_type;
}

QUaDataType::operator QString() const
{
	return QUaDataType::stringByQType(m_type);
}

bool QUaDataType::operator==(const QMetaType::Type& metaType)
{
	return m_type == metaType;
}

void QUaDataType::operator=(const QString& strType)
{
	Q_ASSERT_X(QUaDataType::m_custTypesByName.contains(strType), "QUaDataType", "Unknown type");
	if (!QUaDataType::m_custTypesByName.contains(strType))
	{
		m_type = QMetaType::UnknownType;
		return;
	}
	m_type = QUaDataType::m_custTypesByName[strType];
}

bool QUaDataType::isSupportedQType(const QMetaType::Type& type)
{
	return m_custTypesByType.contains(type);
}

QMetaType::Type QUaDataType::qTypeByNodeId(const UA_NodeId& nodeId)
{
	Q_ASSERT(m_custTypesByNodeId.contains(nodeId));
	return m_custTypesByNodeId.value(nodeId, QMetaType::UnknownType);
}

QMetaType::Type QUaDataType::qTypeByTypeIndex(const int& typeIndex)
{
	Q_ASSERT(m_custTypesByTypeIndex.contains(typeIndex));
	return m_custTypesByTypeIndex.value(typeIndex, QMetaType::UnknownType);
}

UA_NodeId QUaDataType::nodeIdByQType(const QMetaType::Type& type)
{
	Q_ASSERT(m_custTypesByType.contains(type));
	if (!m_custTypesByType.contains(type))
	{
		return UA_NODEID_NULL;
	}
	return m_custTypesByType[type].nodeId;
}

const UA_DataType* QUaDataType::dataTypeByQType(const QMetaType::Type& type)
{
	Q_ASSERT(m_custTypesByType.contains(type));
	if (!m_custTypesByType.contains(type))
	{
		return nullptr;
	}
	return m_custTypesByType[type].dataType;
}

QString QUaDataType::stringByQType(const QMetaType::Type& type)
{
	Q_ASSERT(m_custTypesByType.contains(type));
	if (!m_custTypesByType.contains(type))
	{
		return QString("UnknownType");
	}
	return m_custTypesByType[type].name;
}

QMetaEnum QUaStatusCode::m_metaEnum = QMetaEnum::fromType<QUa::Status>();

// init static hash
QHash<QUaStatus, QString> QUaStatusCode::m_descriptions =
[]() -> QHash<QUaStatus, QString> {
	QHash<QUaStatus, QString> retHash;
	retHash[QUaStatus::Good                                   ] = QObject::tr("The operation was successful and the associated results may be used"                                       );
	retHash[QUaStatus::GoodLocalOverride                      ] = QObject::tr("The value has been overridden"                                                                             );
	retHash[QUaStatus::Uncertain                              ] = QObject::tr("The operation was partially successful and that associated results might not be suitable for some purposes");
	retHash[QUaStatus::UncertainNoCommunicationLastUsableValue] = QObject::tr("Communication to the data source has failed. The variable value is the last value that had a good quality" );
	retHash[QUaStatus::UncertainLastUsableValue               ] = QObject::tr("Whatever was updating this value has stopped doing so"                                                     );
	retHash[QUaStatus::UncertainSubstituteValue               ] = QObject::tr("The value is an operational value that was manually overwritten"                                           );
	retHash[QUaStatus::UncertainInitialValue                  ] = QObject::tr("The value is an initial value for a variable that normally receives its value from another variable"       );
	retHash[QUaStatus::UncertainSensorNotAccurate             ] = QObject::tr("The value is at one of the sensor limits"                                                                  );
	retHash[QUaStatus::UncertainEngineeringUnitsExceeded      ] = QObject::tr("The value is outside of the range of values defined for this parameter"                                    );
	retHash[QUaStatus::UncertainSubNormal                     ] = QObject::tr("The value is derived from multiple sources and has less than the required number of Good sources"            );
	retHash[QUaStatus::Bad                                    ] = QObject::tr("The operation failed and any associated results cannot be used"                                            );
	retHash[QUaStatus::BadConfigurationError                  ] = QObject::tr("There is a problem with the configuration that affects the usefulness of the value"                        );
	retHash[QUaStatus::BadNotConnected                        ] = QObject::tr("The variable should receive its value from another variable, but has never been configured to do so"       );
	retHash[QUaStatus::BadDeviceFailure                       ] = QObject::tr("There has been a failure in the device/data source that generates the value that has affected the value"   );
	retHash[QUaStatus::BadSensorFailure                       ] = QObject::tr("There has been a failure in the sensor from which the value is derived by the device/data source"          );
	retHash[QUaStatus::BadOutOfService                        ] = QObject::tr("The source of the data is not operational"                                                                 );
	retHash[QUaStatus::BadDeadbandFilterInvalid               ] = QObject::tr("The deadband filter is not valid"                                                                          );
	return retHash;
}();
QString QUaStatusCode::longDescription(const QUaStatusCode& statusCode)
{
	return QUaStatusCode::m_descriptions.value(
		statusCode, 
		QObject::tr("Unknown description value %1")
			.arg(static_cast<quint32>(statusCode))
	);
}

QUaStatusCode::QUaStatusCode()
{
	m_status = QUaStatus::Good;
}

QUaStatusCode::QUaStatusCode(const QUaStatus& uaStatus)
{
	m_status = uaStatus;
}

QUaStatusCode::QUaStatusCode(const UA_StatusCode& intStatus)
{
	m_status = static_cast<QUaStatus>(intStatus);
}

QUaStatusCode::QUaStatusCode(const QString& strStatus)
{
	*this = QUaStatusCode(strStatus.toUtf8());
}

QUaStatusCode::QUaStatusCode(const QByteArray& byteStatus)
{
	bool ok = false;
	int val = m_metaEnum.keyToValue(byteStatus.constData(), &ok);
	m_status = static_cast<QUaStatus>(val);
}

QUaStatusCode::operator QUaStatus() const
{
	return static_cast<QUaStatus>(m_status);
}

QUaStatusCode::operator UA_StatusCode() const
{
	return static_cast<UA_StatusCode>(m_status);
}

QUaStatusCode::operator QString() const
{
	const char* code = m_metaEnum.valueToKey(static_cast<int>(m_status));
	if (!code)
	{
		code = UA_StatusCode_name(static_cast<UA_StatusCode>(m_status));
	}
	return QString(code);
}

bool QUaStatusCode::operator==(const QUaStatus& uaStatus)
{
	return m_status == uaStatus;
}

void QUaStatusCode::operator=(const QString& strStatus)
{
	*this = QUaStatusCode(strStatus.toUtf8());
}

QUaQualifiedName::QUaQualifiedName()
{
	m_namespace = 0;
	m_name = QString();
}

QUaQualifiedName::QUaQualifiedName(const quint16& namespaceIndex, const QString& name)
{
	m_namespace = namespaceIndex;
	m_name = name;
}

QUaQualifiedName::QUaQualifiedName(const UA_QualifiedName& uaQualName)
{
	// use overloaded equality operator
	*this = uaQualName;
}

QUaQualifiedName::QUaQualifiedName(const QString& strXmlQualName)
{
	// use overloaded equality operator
	*this = strXmlQualName;
}

QUaQualifiedName::QUaQualifiedName(const char* strXmlQualName)
{
	// use overloaded equality operator
	*this = strXmlQualName;
}

QUaQualifiedName::operator UA_QualifiedName() const
{
	UA_QualifiedName browseName;
	browseName.namespaceIndex = m_namespace;
	browseName.name = QUaTypesConverter::uaStringFromQString(m_name); // NOTE : allocs
	return browseName;
}

QUaQualifiedName::operator QString() const
{
	return QString("ns=%1;s=%2").arg(m_namespace).arg(m_name);
}

void QUaQualifiedName::operator=(const UA_QualifiedName& uaQualName)
{
	m_namespace = uaQualName.namespaceIndex;
	m_name = QUaTypesConverter::uaStringToQString(uaQualName.name);
}

void QUaQualifiedName::operator=(const QString& strXmlQualName)
{
	m_namespace = 0;
	m_name = strXmlQualName;
	QStringList components = strXmlQualName.split(QLatin1String(";"));
	// check if valid xml format
	if (components.size() != 2)
	{
		// if no valid xml format, assume ns = 0 and given string is name
		return;
	}
	// check if valid namespace found, else assume ns = 0 and given string is name
	quint16 new_ns;
	if (components.at(0).contains(QRegularExpression(QLatin1String("^ns=[0-9]+")))) {
		bool success = false;
		uint ns = components.at(0).midRef(3).toString().toUInt(&success);
		if (!success || ns > (std::numeric_limits<quint16>::max)())
		{
			return;
		}
		new_ns = ns;
	}
	// check if valid name found, else assume ns = 0 and given string is name
	if (!components.last().contains(QRegularExpression(QLatin1String("^[isgb]="))))
	{
		return;
	}
	// if reached here, xml format is correct
	m_namespace = new_ns;
	m_name = components.last().midRef(2).toString();
}

void QUaQualifiedName::operator=(const char* strXmlQualName)
{
	// use overloaded equality operator
	*this = QString(strXmlQualName);
}

bool QUaQualifiedName::operator==(const QUaQualifiedName& other) const
{
	return m_namespace == other.m_namespace &&
		m_name.compare(other.m_name, Qt::CaseSensitive) == 0;
}

bool QUaQualifiedName::operator!=(const QUaQualifiedName& other) const
{
	return m_namespace != other.m_namespace ||
		m_name.compare(other.m_name, Qt::CaseSensitive) != 0;
}

quint16 QUaQualifiedName::namespaceIndex() const
{
	return m_namespace;
}

void QUaQualifiedName::setNamespaceIndex(const quint16& namespaceIndex)
{
	m_namespace = namespaceIndex;
}

QString QUaQualifiedName::name() const
{
	return m_name;
}

void QUaQualifiedName::seName(const QString& name)
{
	m_name = name;
}

QString QUaQualifiedName::toXmlString() const
{
	// use ::operator QString()
	return *this;
}

UA_QualifiedName QUaQualifiedName::toUaQualifiedName() const
{
	// use ::operator UA_QualifiedName()
	return *this;
}

QUaQualifiedName QUaQualifiedName::fromXmlString(const QString& strXmlQualName)
{
	return QUaQualifiedName(strXmlQualName);
}

QUaQualifiedName QUaQualifiedName::fromUaQualifiedName(const UA_QualifiedName& uaQualName)
{
	return QUaQualifiedName(uaQualName);
}

QUaChangeStructureDataType::QUaChangeStructureDataType()
	: m_strNodeIdAffected(""),
	m_strNodeIdAffectedType(""),
	m_uiVerb(QUaChangeVerb::NodeAdded)
{
}

QUaChangeStructureDataType::QUaChangeStructureDataType(
	const QUaNodeId& strNodeIdAffected,
	const QUaNodeId& strNodeIdAffectedType,
	const Verb& uiVerb)
	: m_strNodeIdAffected(strNodeIdAffected),
	m_strNodeIdAffectedType(strNodeIdAffectedType),
	m_uiVerb(uiVerb)
{
}

QUaSession::QUaSession(QObject* parent/* = 0*/)
	: QObject(parent)
{
	m_timestamp = QDateTime::currentDateTimeUtc();
}

QString QUaSession::sessionId() const
{
	return m_strSessionId;
}

QString QUaSession::userName() const
{
	return m_strUserName;
}

QString QUaSession::applicationName() const
{
	return m_strApplicationName;
}

QString QUaSession::applicationUri() const
{
	return m_strApplicationUri;
}

QString QUaSession::productUri() const
{
	return m_strProductUri;
}

QString QUaSession::address() const
{
	return m_strAddress;
}

quint16 QUaSession::port() const
{
	return m_intPort;
}

QDateTime QUaSession::timestamp() const
{
	return m_timestamp;
}

QUaLocalizedText::QUaLocalizedText()
{
	// TODO :
}

QUaLocalizedText::QUaLocalizedText(const QString& strXmlLocalizedText)
{
	// TODO :
}

QUaLocalizedText::QUaLocalizedText(const char* strXmlLocalizedText)
{
	// TODO :
}

QUaLocalizedText::operator QString() const
{
	// TODO :
	return QString();
}

void QUaLocalizedText::operator=(const QString& strXmlLocalizedText)
{
	// TODO :
}

QUaNodeId::QUaNodeId()
{
	// TODO :
}

QUaNodeId::QUaNodeId(const UA_NodeId& uaNodeId)
{
	// TODO :
}

QUaNodeId::QUaNodeId(const QString& strXmlNodeId)
{
	// TODO :
}

QUaNodeId::QUaNodeId(const char* strXmlNodeId)
{
	// TODO :
}

QUaNodeId::operator UA_NodeId() const
{
	// TODO :
	return UA_NODEID_NULL;
}

QUaNodeId::operator QString() const
{
	// TODO :
	return QString();
}

bool QUaNodeId::operator==(const QUaNodeId& other) const
{
	// TODO :
	return false;
}
