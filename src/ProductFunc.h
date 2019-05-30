#ifndef PRODUCT_FUNCTION_DOT_H
#define PRODUCT_FUNCTION_DOT_H

#ifndef __cplusplus
#include <stdbool.h>
#endif


#if defined(__cplusplus)
extern "C" {
#endif
    bool FindFileAndCountLines(); //Regresa 1 si el archivo no se encontró
    void AgregarProducto();
#if defined(__cplusplus)
}
#endif

#endif