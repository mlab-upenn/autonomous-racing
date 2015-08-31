all: libpowutil.so client

libpowutil.so: powutil.c parsec_barrier.c
	gcc -Wall -O3 -g -std=c99 -fpic $^ -c
	gcc -shared -o $@ $(^:.c=.o)

# NB: client code needs to link with "-lpowutil -pthread"
client: pu-client.c
	gcc -Wall -O3 -g -std=c99 -L. $^ -pthread -lpowutil -o $@

clean:
	rm -f *.o libpowutil.so client

