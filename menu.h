/*----------------------------------------menu.h--------------------------------------------*/


#ifndef MENU_H
#define MENU_H
enum network_mode {
    Auto,
    AdHoc,
    Managed,
    Master,
    Repeater,
    Secondary,
    Monitor,
    Unknown
};



struct ap_scan_info
{
    unsigned char mac[6];        // Cell MAC
    char essid[15];              // ESSID
    enum network_mode mode;      // Operation mode (enumeration)
    int channel;                 // Channel for transmission
    unsigned short encrypted;    // Boolean stating if net is encrypted 
    unsigned int quality[2];     // Two integers stating quality current/max
};

/*Funciones externas*/
long int data_read();

/*Prototipos de funciones*/
void menu();
int array_load(struct ap_scan_info array_wifi[], int error);
void show_info(struct ap_scan_info array_wifi[], int error);
void choose_net(struct ap_scan_info array_wifi[], int error);

#endif
