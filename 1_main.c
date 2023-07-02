#include <stdio.h>
#include <gtk/gtk.h>

static void activate_application (GtkApplication* app, gpointer user_data){
  GtkWidget *window_1;

  window_1 = gtk_application_window_new (app);
  gtk_window_set_title(GTK_WINDOW(window_1), "Crosses and circles");
  gtk_window_set_default_size(GTK_WINDOW(window_1), 400, 400);
  gtk_window_present(GTK_WINDOW(window_1));
}

int main (int argc, char **argv){
  GtkApplication * application;
  int status;

  application = gtk_application_new("crosses.and.circles._1", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(application, "activate", G_CALLBACK(activate_application), NULL);
  status = g_application_run(G_APPLICATION(application), argc, argv);
  g_object_unref(application);

  return status;
}
