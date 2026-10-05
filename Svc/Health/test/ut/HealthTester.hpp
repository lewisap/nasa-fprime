// ======================================================================
// \title  Health/test/ut/Tester.hpp
// \author jdperez
// \brief  hpp file for Health test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TESTER_HPP
#define TESTER_HPP

#include "HealthGTestBase.hpp"
#include "Svc/Health/HealthComponentImpl.hpp"

namespace Svc {

class HealthTester : public HealthGTestBase {
    // ----------------------------------------------------------------------
    // Construction and destruction
    // ----------------------------------------------------------------------

  public:
    //! Construct object HealthTester
    //!
    HealthTester();

    //! Destroy object HealthTester
    //!
    ~HealthTester();

  public:
    // ----------------------------------------------------------------------
    // Tests
    // ----------------------------------------------------------------------

    void nominalTlm();
    void warningTlm();
    void faultTlm();
    void equalWarnFatalCycles();
    void disableAllMonitoring();
    void disableOneMonitoring();
    void updatePingTimeout();
    void watchdogCheck();
    void nominalCmd();
    void nominal2CmdsDuringTlm();
    void miscellaneous();
    void rejectZeroFatalThreshold();
    void rejectZeroWarningThreshold();
    void rejectFatalBelowElapsedCycles();

  private:
    // ----------------------------------------------------------------------
    // Handlers for typed from ports
    // ----------------------------------------------------------------------

    //! Handler for from_PingSend
    //!
    void from_PingSend_handler(const FwIndexType portNum,  //!< The port number
                               U32 key                     //!< Value to return to pinger
                               ) override;

    //! Handler for from_WdogStroke
    //!
    void from_WdogStroke_handler(const FwIndexType portNum,  //!< The port number
                                 U32 code                    //!< Watchdog stroke code
                                 ) override;

  private:
    // ----------------------------------------------------------------------
    // Helper methods
    // ----------------------------------------------------------------------

    //! Connect ports
    //!
    void connectPorts();

    //! Initialize components
    //!
    void initComponents();

    void dispatchAll();

    //! Pick a random ping table entry
    FwIndexType pickEntry() const;

    //! Invoke the Run port a number of times without answering any ping
    void runCycles(U32 cycles);

    //! Send HLTH_CHNG_PING for an entry and dispatch it
    void sendChngPing(FwIndexType entry, U32 warningValue, U32 fatalValue);

    //! Assert HLTH_CHNG_PING was rejected and the entry kept its configured thresholds
    void assertChngPingRejected(FwIndexType entry, U32 warningValue, U32 fatalValue);

    //! Assert HLTH_CHNG_PING was accepted and the entry now holds the new thresholds
    void assertChngPingAccepted(FwIndexType entry, U32 warningValue, U32 fatalValue);

  private:
    // ----------------------------------------------------------------------
    // Variables
    // ----------------------------------------------------------------------

    FwIndexType numPingEntries;
    HealthImpl::PingEntry pingEntries[Svc::HealthComponentBase::NUM_PINGSEND_OUTPUT_PORTS];
    U32 watchDogCode;
    U32 keys[Svc::HealthComponentBase::NUM_PINGSEND_OUTPUT_PORTS];
    bool override;
    U32 override_key;

    //! The component under test
    //!
    HealthImpl component;

    void textLogIn(const FwEventIdType id,          //!< The event ID
                   const Fw::Time& timeTag,         //!< The time
                   const Fw::LogSeverity severity,  //!< The severity
                   const Fw::TextLogString& text    //!< The event string
                   ) override;

  public:
    // ----------------------------------------------------------------------
    // Accessor methods for protected/private members
    // ----------------------------------------------------------------------
    //! Get the NUM_PINGSEND_OUTPUT_PORTS value
    static constexpr FwSizeType getNumPingSendOutputPorts() { return HealthComponentBase::NUM_PINGSEND_OUTPUT_PORTS; }
};

}  // end namespace Svc

#endif
