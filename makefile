
HOMEDIR = .

SRC = ${HOMEDIR}/main.c ${HOMEDIR}/random.c

make: ${SRC}
	gcc ${SRC} -o prng

clean:
	rm ${HOMEDIR}/prng
