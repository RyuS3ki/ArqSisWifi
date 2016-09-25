/**CFile************************************************************************

  Fichero     array_operations.c

  Resumen     Archivo .c que inicializa el array con los datos de las redes wifi
	      Adicionalmente incluirá las funciones diseñadas por los estudiantes
              para completar la funcionalidad del programa.

-------------------------------------------------------------------------------*/
#include <stdio.h>
#include "menu.h"

#define ARRAY_SIZE 6

/*---------------------------------------------------------------------------*/
/*                      Definición de las variables                          */
/*---------------------------------------------------------------------------*/

struct ap_scan_info wifi[ARRAY_SIZE];

/*---------------------------------------------------------------------------*/
/*                      Definición de las funciones                          */
/*---------------------------------------------------------------------------*/

void array_load(struct ap_scan_info array_wifi[])
{
  int i;

/*Crea array que contiene los datos que los estudiantes usarán para completar
  la práctica*/

  static struct ap_scan_info wifi[] = {
    {{0x5F, 0xF3, 0xB1, 0x9D, 0x50, 0x2C}, "WiFi-UC3M", 6, 48, 0, {0,95}},
    {{0x61, 0x99, 0x7E, 0x9F, 0xEC, 0xFC}, "Livebox-F568", 5, 13, 1, {33,74}},
    {{0xB5, 0x97, 0x88, 0xA8, 0x99, 0x28}, "TESTGAST", 2, 64, 0, {39,38}},
    {{0x7F, 0x48, 0xFD, 0xC8, 0xC9, 0x73}, "eduroam", 0, 16, 0, {0,90}},
    {{0x4E, 0x38, 0x49, 0xB5, 0x87, 0x9F}, "GAST-WIFI-LDAP", 6, 49, 0, {24,100}},
    {{0x64, 0xEA, 0x9A, 0x6B, 0xD4, 0x8C}, "WLITa", 2, 41, 1, {8,72}}
  };
}

/*Menu a mostrar al usuario*/

  void menu(){
    printf("\t\t<MENU>\n");
    printf("[1]\tCargar información de redes wifi\n");
    printf("[2]\tMostrar las redes activas\n");
    printf("[3]\tElegir y mostrar la información de una red\n");
    printf("[4]\tSalir\n");
  }

/*-----Lee cada posición del array y la saca por pantalla-----*/



  void show_info(struct ap_scan_info array_wifi[]){
    int i = 0;
    while (i<ARRAY_SIZE) {
      printf("%s\t %s\n", wifi[i].mac, wifi[i].essid);
    }
  }


  void select(long int opt){
    switch (opt) {
      case 1:
        array_load(wifi);
        break;
      case 2:
//        show_info(wifi[]);
        break;
      case 3:
//        choose_net();
        break;
      case 4:
        exit(0);
    }
  }



/*---------Main----------*/

  int main(int argc, char const *argv[]) {

    while(1){

    menu();
    long int opt = data_read();
    select(opt);

    }

    return 0;

}
