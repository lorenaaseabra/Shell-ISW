CC = gcc

objects =  shell.o func.o 

shell: $(objects)
	${CC} -o shell $(objects)

shell.o: lmvs.h

func.o: lmvs.h

.PHONY: clean
clean: 
	rm shell $(objects)
