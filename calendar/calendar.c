//
//  calendar.c
//  calendar
//
//  Created by Patrick Günthard on 27.12.17.
//  Copyright © 2017 Patrick Günthard. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "calendar.h"
#include "util.h"

cal_entry create_cal_entry (char* title, char* description, unsigned long start, unsigned long end) {
    cal_entry entry = {};
    
    char to_hash[DESCRIPTION_SIZE + TITLE_SIZE + 2*(sizeof(long))];
    strcpy(entry.title, title);
    strcpy(entry.description, description);
    
    sprintf(to_hash,"%s%s%lu%lu", entry.title, entry.description, entry.start, entry.end);
    
    entry.entry_id = hash(to_hash);
    
    return entry;
}

cal_entry_list create_cal_entry_list() {
    cal_entry_list list;
    list.next_entry = NULL;
    return list;
}


cal_entry_list * add_to_cal_entry_list(cal_entry_list *list, cal_entry entry) {
    cal_entry_list temp, *p;
    temp = create_cal_entry_list();
    temp.entry = &entry;
    if(list == NULL) {
        list = &temp;
    }
    else {
        p = list;
        while(p->next_entry != NULL){
            p = p->next_entry;
        }
        p->next_entry = &temp;
    }
    return list;
}
