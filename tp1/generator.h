#ifndef GENERATOR_H
#define GENERATOR_H

#include "bus.h"
#include "ensitlm.h"

using namespace std;
using namespace sc_core;

struct generator : sc_core::sc_module {
    ensitlm::initiator_socket<generator> socket;
	void thread(void);

	SC_CTOR(generator);
};


#endif
