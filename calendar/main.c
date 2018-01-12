//
//  main.c
//  calendar
//
//  Created by Patrick Günthard on 27.12.17.
//  Copyright © 2017 Patrick Günthard. All rights reserved.
//

#define TESTING 1

#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include "calendar.h"
#include "calfile.h"

char * help_text =
"calendar - organise\n\
\n\
add     [ID]\n\
edit    ID\n\
delete  ID\n";

int main(int argc, const char * argv[]) {
    if(TESTING) {
        load_entries();
        
        cal_entry entry = create_cal_entry("title", "description", 1, 2);
        printf("%s: %lu\n",entry.title, entry.entry_id);
        entry = create_cal_entry("title2", "description2", 1, 2);
        printf("%s: %lu\n",entry.title, entry.entry_id);
        entry = create_cal_entry("title3", "description3", 1, 2);
        printf("%s: %lu\n",entry.title, entry.entry_id);
    }
    else {
    
        if(argc < 2) {
            fprintf(stdout, "%s\n", help_text);
        }
        else {
        
            DIR           *d;
            struct dirent *dir;
            d = opendir("~/.cal/");
            if (d) {
                while ((dir = readdir(d)) != NULL) {
                    printf("%s\n", dir->d_name);
                }
                
                closedir(d);
            }
            else {
                fprintf(stdout,"No calendar files found\n");
            }
        }
    }
    return 0;
}
