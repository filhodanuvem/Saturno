package main 

/*
#include <stdio.h>
#include <stdlib.h>
*/
import "C"

func main() {
    value := C.CString("Oi\n")
    C.fputs(value, (*C.FILE)(C.stdout))
}