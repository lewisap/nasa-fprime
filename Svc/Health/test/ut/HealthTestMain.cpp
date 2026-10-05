// ----------------------------------------------------------------------
// Main.cpp
// ----------------------------------------------------------------------

#include "HealthTester.hpp"
#include "STest/Random/Random.hpp"

TEST(Test, NominalTlm) {
    Svc::HealthTester tester;
    tester.nominalTlm();
}

TEST(Test, WarningTlm) {
    Svc::HealthTester tester;
    tester.warningTlm();
}

TEST(Test, FaultTlm) {
    Svc::HealthTester tester;
    tester.faultTlm();
}

TEST(Test, EqualWarnFatalCycles) {
    Svc::HealthTester tester;
    tester.equalWarnFatalCycles();
}

TEST(Test, DisableAllMonitoring) {
    Svc::HealthTester tester;
    tester.disableAllMonitoring();
}

TEST(Test, DisableOneMonitoring) {
    Svc::HealthTester tester;
    tester.disableOneMonitoring();
}

TEST(Test, UpdatePingTimeout) {
    Svc::HealthTester tester;
    tester.updatePingTimeout();
}

TEST(Test, WatchdogCheck) {
    Svc::HealthTester tester;
    tester.watchdogCheck();
}

TEST(Test, NominalCmd) {
    Svc::HealthTester tester;
    tester.nominalCmd();
}

TEST(Test, Nominal2CmdsDuringTlm) {
    Svc::HealthTester tester;
    tester.nominal2CmdsDuringTlm();
}

TEST(Test, Miscellaneous) {
    Svc::HealthTester tester;
    tester.miscellaneous();
}

TEST(Test, RejectZeroFatalThreshold) {
    Svc::HealthTester tester;
    tester.rejectZeroFatalThreshold();
}

TEST(Test, RejectZeroWarningThreshold) {
    Svc::HealthTester tester;
    tester.rejectZeroWarningThreshold();
}

TEST(Test, RejectFatalBelowElapsedCycles) {
    Svc::HealthTester tester;
    tester.rejectFatalBelowElapsedCycles();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    STest::Random::seed();
    return RUN_ALL_TESTS();
}
