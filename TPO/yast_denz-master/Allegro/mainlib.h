#include "allegro.h"
#include "arrow.h"
#include "background.h"
#include "element.h"
#include "game.h"
#include "server.h"

#include <pthread.h>

void *serverThread(void *);
void sighandler(int);