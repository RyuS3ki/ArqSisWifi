/**CFile************************************************************************

  Fichero     array_operations.c

  Resumen     Archivo .c que inicializa el array con los datos de las redes wifi
	      Adicionalmente incluirá las funciones diseñadas por los estudiantes
              para completar la funcionalidad del programa.

-------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

/*---------------------------------------------------------------------------*/
/*                      Definición de las variables                          */
/*---------------------------------------------------------------------------*/

#define ARRAY_SIZE 6
#define MAC_SIZE 6
#define ESSID_SIZE 15
#define QUAL_SIZE 2

/*---------------------------------------------------------------------------*/
/*                      Definición de las funciones                          */
/*---------------------------------------------------------------------------*/

void array_load(struct ap_scan_info array_wifi[]){
	
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
	
	for(i=0; i<ARRAY_SIZE; i++){
		
		strncpy(array_wifi[i].mac, wifi[i].mac, 6);
		strncpy(array_wifi[i].essid, wifi[i].essid, 15);
		array_wifi[i].mode = wifi[i].mode;
		array_wifi[i].channel = wifi[i].channel;
		array_wifi[i].encrypted = wifi[i].encrypted;
		array_wifi[i].quality[0] = wifi[i].quality[0];
		array_wifi[i].quality[1] = wifi[i].quality[1];
	}
	
	printf("Información cargada correctamente.\n");
	
}

/*Menu a mostrar al usuario*/

  void menu(){
    printf("\n\t\t<MENU>\n");
    printf("[1]\tCargar información de redes wifi\n");
    printf("[2]\tMostrar las redes activas\n");
    printf("[3]\tElegir y mostrar la información de una red\n");
    printf("[4]\tSalir\n");
		printf("Teclee una opción: ");
  }


  /*-----Lee cada posición del array y la saca por pantalla-----*/

  void show_info(struct ap_scan_info array_wifi[]){
    int i = 0;
		int j = 0;
    printf("%-8s%-20s%-20s%-8s%-8s%-13s%s\n","No.Red","SSID","MAC","Modo","Canal","Encriptada","Calidad");
	  printf("------------------------------------------------------------------------------------------------\n");
    while (i<ARRAY_SIZE) {
      printf("%-8d", i);
      printf("%-20s",array_wifi[i].essid);
	    printf("%-x:",array_wifi[i].mac[0]);
				for(j = 1; j<(MAC_SIZE-1); j++){
					printf("%-x:", array_wifi[i].mac[j]);
				}
			printf("%-5x", array_wifi[i].mac[MAC_SIZE]);
	    printf("%-8d",array_wifi[i].mode);
			printf("%-8d",array_wifi[i].channel);
			printf("%-13d",array_wifi[i].encrypted);
			printf("%u\n", array_wifi[i].quality[0]);
	    i++;
    }
  }

void choose_net(struct ap_scan_info array_wifi[]){
	int j;
	printf("Introduzca un número de ID: ");
	int id = data_read();
	printf("No. Red: %d\nSSID: %s\n", id, array_wifi[id].essid);
	printf("MAC: ");
				for(j = 0; j<(MAC_SIZE-1); j++){
					printf("%x:", array_wifi[id].mac[j]);
				}
	printf("%x\n",array_wifi[id].mac[MAC_SIZE]);
	printf("Modo: %d\nCanal: %d\nEncriptada: \n", array_wifi[id].mode, array_wifi[id].channel, array_wifi[id].encrypted);
	printf("Calidad: %u/%u\n\n", array_wifi[id].quality[0], array_wifi[id].quality[1]);
}

/*---------Main----------*/

  int main(int argc, char const *argv[]) {

    struct ap_scan_info arrwf[ARRAY_SIZE];
    
    while(1){

      menu();
      long int option = data_read();
			
/*Función switch para elegir opción del menú*/
			
      switch (option) {
	case 1:
	  array_load(arrwf);
	  break;
		      
	case 2:
	  show_info(arrwf);
	  break;
		      
	case 3:
//        choose_net();
	  printf("\nFuncionalidad en construcción, disculpe las molestias.\n\n\n");
	  break;
		      
	case 4:
	  printf("\nFinalizando sesión...\n¡Hasta pronto!\n");
	  exit(0);
      }
    }
    return 0;
}
