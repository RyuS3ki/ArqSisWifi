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

/*Pease add the prototypes of the functions needed to complete the program*/
//It allow us use the function read_data() from data_read.o.

extern long int data_read();

#endif