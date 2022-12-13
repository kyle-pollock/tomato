#include <unistd.h>
#include <libnotify/notify.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SECONDS (60 * 25)

void setTriggerTime(struct tm *lt, int seconds) {
	lt->tm_sec += seconds;
	mktime(lt);
}

void printTriggerTime(struct tm *lt) {
	printf("🍅 @ %02d:%02d:%02d\n", lt->tm_hour, lt->tm_min, lt->tm_sec);
}

void notify() {
	notify_init("tomato");
	NotifyNotification *notif = notify_notification_new("Tomato Up!", "🍅 🍅 🍅", NULL);
	notify_notification_show(notif, NULL);
	g_object_unref(G_OBJECT(notif));
	notify_uninit();
}

int main(int argc, char *argv[]) {
	int seconds = DEFAULT_SECONDS;
	int minutes = 0;

	if (argc == 2) {
		minutes = atoi(argv[1]);
	}
	if (minutes > 0) {
		seconds = 60 * minutes;
	}

	time_t t = time(NULL);
	struct tm *lt = localtime(&t);
	setTriggerTime(lt, seconds);
	printTriggerTime(lt);

	sleep(seconds);

	notify();
	return 0;
}
