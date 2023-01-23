/********************************************************************
 * Copyright (C) 2009 by Ensimag and Verimag			    *
 * Initial author: Matthieu Moy					    *
 ********************************************************************/

#include "generator.h"
#include "bus.h"
#include "memory.h"

int sc_main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	/*
	  +---------+	 +-------------+    +--------+
	  |	   +++	+-+	      +++  +++	     |
	  | Generator1  | +--+ |  Router   | +--+ |	mémoire  |
	  |	   +++	+-+	      +++  +++	     |
	  +---------+	 +-------------+    +--------+
	*/

	generator gen ("Generator1");
	Bus router("Router");
    memory mem("mémoire",256);

    /* Memory is mapped at 0X10000000 */
    router.map(mem.socket, 0x10000000,mem.size);
	/* connect components to the bus */
	gen.socket.bind(router.target);
    router.initiator.bind(mem.socket);
    

	/* and start simulation */
	sc_core::sc_start();
	return 0;
}
