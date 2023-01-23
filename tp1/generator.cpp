#include "generator.h"

using namespace std;

void generator::thread(void) {
	ensitlm::data_t val = 1;
	ensitlm::addr_t addr = 0x10000000;
	for(int i=0; i<10; i++, addr +=4){
		cout << "Entrer un nombre" << endl;
		cin >> val;
		cout << "je vais envoyer : " << std::dec << val << endl;
		socket.write(addr, val);
	}
    for(int i=0; i<40; i+= 4){
		socket.read(0x10000000 + i, val);
}
        socket.write(0x10000000,53.3);
		// socket.read(0x10000000 + 3, val); to test that it fails
 
}

generator::generator(sc_core::sc_module_name name) : sc_core::sc_module(name) {
	SC_THREAD(thread);
}
