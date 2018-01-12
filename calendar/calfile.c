//
//  calfile.c
//  calendar
//
//  Created by Patrick Günthard on 29.12.17.
//  Copyright © 2017 Patrick Günthard. All rights reserved.
//

#include "calfile.h"
#include "calendar.h"

#include <dirent.h>


cal_entry * load_entries() {
    DIR           *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        
        closedir(d);
    }

    return NULL;
}


