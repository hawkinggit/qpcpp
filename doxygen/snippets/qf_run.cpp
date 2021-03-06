void QActive::run(void) {
    m_running = true;
    while (m_running) {
        QEvt const *e;
        QACTIVE_GET_(this, e); // wait for an event
        dispatch(e);    // dispatch event to the active object's state machine
        QF::gc(e);      // check if the event is garbage, and collect it if so
    }

    unsubscribeAll();   // unsubscribe from all signals
    QF::remove_(this);  // remove this object from any subscriptions
}
