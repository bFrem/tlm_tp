#include "memory.h"


tlm::tlm_response_status memory::write(const ensitlm::addr_t &a,
                                    const ensitlm::data_t &d){
    storage[a/sizeof(size)]=d;
    cout<< "j'écris : " << d <<  ", dans la mémoire à l'adresse : " << a << endl;
    return tlm::TLM_OK_RESPONSE;

}

tlm::tlm_response_status memory::read(const ensitlm::addr_t &a,
	                              const ensitlm::data_t &d){
    if (a>size){
        cout << "Sortie des limites de la mémoire";
        return tlm::TLM_ADDRESS_ERROR_RESPONSE;
    }
    else{
    cout<< "je lis : " << storage[a/sizeof(size)]  <<  ", dans la mémoire à l'adresse : " << a << endl;
    return tlm::TLM_OK_RESPONSE;
    }
}
memory::memory(sc_core::sc_module_name name, uint32_t mem_size) : sc_core::sc_module(name) {
    storage = new ensitlm::data_t[mem_size/sizeof(mem_size)];
    size = mem_size/sizeof(mem_size);
}

memory::~memory() {
    delete (storage);
}