#include "giorgio.h"

//used to ensure each new event has a unique eventID
int numEvents = 1;

//function used to create a new event
Event createEvent(int time, int eventType) {
    Event e;
	e.time = time;
    e.eventType = eventType;
	e.eventID = numEvents;
	numEvents++;
    return e;
}

//function used to change the time and type of an event after it completes a job by creating a new event and transferring the eventID
Event createEventWithID(int time, int eventType, int eventID) {
	Event e;
	e.time = time;
	e.eventType = eventType;
	e.eventID = eventID;
	return e;
}

//function used to return the String of an eventType, used for debugging
char* getEventType(int eventType) {
	if(eventType == 1) {
		return "CPU STARTED";
	} else if (eventType == 2) {
		return "CPU FINISHED";
	} else if (eventType == 3) {
		return "DISK1 STARTED";
	} else if (eventType == 4) {
		return "DISK1 FINISHED";
	} else if (eventType == 5) {
		return "DISK2 STARTED";
	} else if (eventType == 6) {
		return "DISK2 FINISHED";
	} else if (eventType == 7) {
		return "JOB ARRIVED";
	} else if (eventType == 8) {
		return "JOB TERMINATED";
	} else if (eventType == 9) {
		return "SIMULATION TERMINATED";
	}
	return "FAILED TO IDENTIFY EVENT TYPE";
}

//prints an event, used for debugging
void printEvent(Event e) {
	printf("Time: %d    Job Number: %d    Event: %s\n", e.time, e.eventID, getEventType(e.eventType));
}