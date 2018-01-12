//
//  calendar.h
//  calendar
//
//  Created by Patrick Günthard on 27.12.17.
//  Copyright © 2017 Patrick Günthard. All rights reserved.
//

#ifndef calendar_h
#define calendar_h

#define DESCRIPTION_SIZE 4096
#define TITLE_SIZE 256

struct s_cal_entry {
    unsigned long entry_id;
    char title[TITLE_SIZE];
    char description[DESCRIPTION_SIZE];
    long start;             // Date, UNIX Time
    long end;               // Date, UNIX Time
};

typedef struct s_cal_entry cal_entry;

struct s_cal_config {
    char cal_file_dir[256];
};

typedef struct s_cal_config cal_config;


struct s_cal_entry_list {
    cal_entry entry;
    struct s_cal_entry_list *next_entry;
};

typedef struct s_cal_entry_list cal_entry_list;

cal_entry create_cal_entry (char*, char*, unsigned long, unsigned long);

#endif /* calendar_h */
