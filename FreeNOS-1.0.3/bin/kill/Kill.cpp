/*
 * Copyright (C) 2009 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <ProcessClient.h>
#include "Kill.h"

Kill::Kill(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Kill a process.");
    parser().registerPositional("PROCESS-ID", "ID of Process to kill.");
}

Kill::~Kill()
{
}

Kill::Result Kill::exec()
{
    ProcessID process_id = atoi(arguments().get("PROCESS-ID"));
    const ProcessClient p_client;
    const ProcessClient::Result success = p_client.killPID(process_id);
    if(success != ProcessClient::Success) {
    	ERROR("Could not kill process with PID `" << process_id << "'");
    	return NotFound;
    } 
   
    return Success;
}


