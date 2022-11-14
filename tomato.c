#include <unistd.h>
#include <libnotify/notify.h>

#define NUM_SECONDS_POMODORO (60 * 25)

int main() {
	notify_init("tomato");
	NotifyNotification *notif = notify_notification_new("Tomato Up!", "🍅 🍅 🍅", NULL);
	sleep(NUM_SECONDS_POMODORO);
	notify_notification_show(notif, NULL);
	g_object_unref(G_OBJECT(notif));
	notify_uninit();
	return 0;
}
