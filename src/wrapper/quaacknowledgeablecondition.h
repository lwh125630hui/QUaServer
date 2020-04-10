#ifndef QUAACKNOWLEDGEABLECONDITION_H
#define QUAACKNOWLEDGEABLECONDITION_H

#include <QUaCondition>

#ifdef UA_ENABLE_SUBSCRIPTIONS_ALARMS_CONDITIONS

/*
Part 9 - 5.7.2 AcknowledgeableConditionType

The AcknowledgeableConditionType extends the ConditionType by defining acknowledgement
characteristics.

HasComponent | Variable | AckedState     | LocalizedText | TwoStateVariableType | Mandatory
HasComponent | Variable | ConfirmedState | LocalizedText | TwoStateVariableType | Optional
HasComponent | Method   | Acknowledge    | Defined in Clause 5.7.3              | Mandatory
HasComponent | Method   | Confirm        | Defined in Clause 5.7.4              | Optional

Acknowledgment of the transition may come from the Client or may be due to some logic internal
to the Server. For example, acknowledgment of a related Condition may result in this Condition
becoming acknowledged, or the Condition may be set up to automatically Acknowledge itself
when the acknowledgeable situation disappears.

The Confirmed Acknowledge model is typically used to differentiate between
acknowledging the presence of a Condition and having done something to address the
Condition.

The AckedState and ConfirmedState are strictly sub-states of the Enabled State (base ConditionType)
They could be independent parallel states, or the server might restrict the ConfirmedState to
Unconfirmed until the AckedState is Acknowledged.

*/


class QUaAcknowledgeableCondition : public QUaCondition
{
    Q_OBJECT

	Q_PROPERTY(bool confirmAllowed READ confirmAllowed WRITE setConfirmAllowed)

friend class QUaServer;

public:
	Q_INVOKABLE explicit QUaAcknowledgeableCondition(
		QUaServer *server
	);

	// children

	// AckedState when False indicates that the Condition instance requires acknowledgement for the
	// reported Condition state.When the Condition instance is acknowledged the AckedState is set
	// to True.  Recommended state names are described in Annex A. 
	// The two states are sub-states of the True EnabledState. The EventId used in the
	// Event Notification is considered the identifier of this state and has to be used when 
	// calling the  Methods for acknowledgement or confirmation.
	QString   ackedStateCurrentStateName() const;
	void      setAckedStateCurrentStateName(const QString& ackedState);
	bool      ackedStateId() const;
	void      setAckedStateId(const bool& ackedStateId);
	QDateTime ackedStateTransitionTime() const;
	void      setAckedStateTransitionTime(const QDateTime& transitionTime);
	QString   ackedStateTrueState() const;
	void      setAckedStateTrueState(const QString& trueState);
	QString   ackedStateFalseState() const;
	void      setAckedStateFalseState(const QString& falseState);
	// helper sets setAckedStateId, setAckedStateCurrentStateName, setAckedStateTransitionTime 
	// and triggers event according to specification
	// NOTE : change of the Acked state must be normally make by the client through
	//        the use of the Acknowledge() and QUaAlarmCondition::Reset() methods
	bool      acknowledged() const;
	void      setAcknowledged(const bool& acknowledged);

	// ConfirmedState indicates whether it requires confirmation.
	// The two states are sub-states of the True EnabledState. The EventId used in the
	// Event Notification is considered the identifier of this state and has to be used when 
	// calling the  Methods for acknowledgement or confirmation.
	QString   confirmedStateCurrentStateName() const;
	void      setConfirmedStateCurrentStateName(const QString& confirmedState);
	bool      confirmedStateId() const;
	void      setConfirmedStateId(const bool& confirmedStateId);
	QDateTime confirmedStateTransitionTime() const;
	void      setConfirmedStateTransitionTime(const QDateTime& transitionTime);
	QString   confirmedStateTrueState() const;
	void      setConfirmedStateTrueState(const QString& trueState);
	QString   confirmedStateFalseState() const;
	void      setConfirmedStateFalseState(const QString& falseState);
	// helper sets setConfirmedStateId, setConfirmedStateCurrentStateName, setConfirmedStateTransitionTime 
	// and triggers event according to specification
	// NOTE : change of the Confirmed state must be normally make by the client through
	//        the use of the Confirm() and QUaAlarmCondition::Reset() methods
	bool      confirmed() const;
	void      setConfirmed(const bool& confirmed);

	// methods

	// The Acknowledge Method is used to acknowledge an Event Notification for a Condition instance
	// state where AckedState is False.
	Q_INVOKABLE void Acknowledge(QByteArray EventId, QString Comment);

	// The Confirm Method is used to confirm an Event Notifications for a Condition instance state
	// where ConfirmedState is False.
	Q_INVOKABLE void Confirm(QByteArray EventId, QString Comment);

	// helpers

	bool confirmAllowed() const;
	void setConfirmAllowed(const bool & confirmAllowed);

signals:
	void acknowledged();

	void confirmed();

protected:
	bool m_confirmAllowed;
	// LocalizedText
	QUaTwoStateVariable* getAckedState();
	// LocalizedText
	QUaTwoStateVariable* getConfirmedState();

	// helpers

	// reimplement to define branch delete conditions
	virtual bool canDeleteBranch() const;
	// reimplement to reset type internals (QUaAlarmCondition::Reset)
	virtual void resetInternals();

};

#endif // UA_ENABLE_SUBSCRIPTIONS_ALARMS_CONDITIONS

#endif // QUAACKNOWLEDGEABLECONDITION_H