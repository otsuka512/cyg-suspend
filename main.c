/* -*- mode: c; c-set-style: "stroustrup"; tab-width: 4; -*-
 *
 * main.c
 *
 * Copyright (C) 2013 Koichi Otsuka
 *
 * Suspend Hibernate Windows
 */

#include <stdio.h>
#include <getopt.h>
#include <windows.h>
#include <powrprof.h>

int main(int argc, char *argv[])
{
  int c;
  int hibernate = FALSE;

  while (1) {
    int option_index = 0;
    static struct option long_options[] = {
      { "hibernate", no_argument, 0, 'h' },
      { "suspend", no_argument,   0, 's' },
      { "help", no_argument, 0, '?' },
      { 0, 0, 0, 0 }
    };

    c = getopt_long(argc, argv, "hs?", long_options, &option_index);
    if (c == -1) break;

    switch (c) {
    case 'h':
      hibernate = TRUE;
      break;
    case 's':
      hibernate = FALSE;
      break;
    case '?':
    default:
      fprintf(stderr, "Usage: cyg-suspend [--hibernate]\n");
      fprintf(stderr, "Suspend Hibernate Windows 0.1\n");
      return 0;
    }
  }

  SetSuspendState(hibernate, FALSE, FALSE);

  return 0;
}

/* End of File */
