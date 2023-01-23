#ifndef MEMORY_H
#define MEMORY_H

#include "bus.h"
#include "ensitlm.h"

using namespace std;
using namespace sc_core;

struct memory : sc_core::sc_module {
	ensitlm::target_socket<memory> socket;
    ensitlm::data_t* storage;
    uint32_t size;

	tlm::tlm_response_status read(const ensitlm::addr_t &a,
	                              const ensitlm::data_t &d);

	tlm::tlm_response_status write(const ensitlm::addr_t &a,
	                                const ensitlm::data_t &d);

    ~memory();

    memory(sc_core::sc_module_name name, uint32_t mem_size);
    
};


#endif