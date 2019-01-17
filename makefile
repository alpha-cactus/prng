
HOMEDIR = .

SRC = ${HOMEDIR}/main.c ${HOMEDIR}/tele_rand.c

make: ${SRC}
	gcc ${SRC} -o prng

clean:
	rm ${HOMEDIR}/prng
