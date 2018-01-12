//
//  util.c
//  calendar
//
//  Created by Patrick Günthard on 27.12.17.
//  Copyright © 2017 Patrick Günthard. All rights reserved.
//

#include "util.h"

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;
    
    while ((c = *str++) != 0) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}
