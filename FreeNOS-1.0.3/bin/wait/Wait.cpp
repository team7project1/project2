
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <Process.h>
#include <ProcessManager.h>
#include <sys/wait.h>
#include "Wait.h"

Wait::Wait(int argc, char** argv) : POSIXApplication(argc, argv)
{
	parser().setDescription("Wait for a state change within the process");
	parser().registerPositional("PROCESS_ID", "Wait for the given process until it returns or finishes");
}

Wait::~Wait() {
	// Nothing
}

// Execution method, performs system call on waitPID using user-provided Process ID.
Wait::Result Wait::exec() {
	ProcessID arg_id;
	int store_result, success;
	// Check if user enters reserved
	if ((arg_id = atoi(arguments().get("PROCESS_ID"))) <= 3) {
		ERROR("Invalid PID `" << arguments().get("PROCESS_ID") << "'");
		return InvalidArgument;
	}

	success = waitpid(arg_id, &store_result, 0);
	if (!success) {
		ERROR("Could not wait for " << arguments().get("PROCESS_ID") << "'");
		return TimedOut;
	}
	return Success;
}
