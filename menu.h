/*---------------------------------LICENSE------------------------------------

    Wi-fi DB emulator programmed in C. Developed for Systems Architecture 
    course, Telematics Engineering Degree, Universidad Carlos III de Madrid.
		
    Copyright (C) 2016  Rebeca Jimenez Guillen, rebecajg@protonmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

-----------------------------------LICENSE-----------------------------------*/




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
extern long int data_read();

/*Prototipos de funciones*/
void menu();
int array_load(struct ap_scan_info array_wifi[], int error);
void show_info(struct ap_scan_info array_wifi[], int error);
void choose_net(struct ap_scan_info array_wifi[], int error);

#endif
