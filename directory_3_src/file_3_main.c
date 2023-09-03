#include <stdio.h>
#include <gtk/gtk.h>
#include "file_1_constants.h"
#include "file_4_scene_1.h"

static void activate (GtkApplication* app, gpointer user_data){
  GtkWidget * level_1_1_window;
  GtkWidget * level_2_1_container;

  level_1_1_window = gtk_application_window_new (app);
  gtk_window_set_title(GTK_WINDOW(level_1_1_window), "Crosses and circles");
  gtk_window_set_default_size(GTK_WINDOW(level_1_1_window), DEFAULT_WIDTH, DEFAULT_HEIGHT);
  gtk_window_set_position(GTK_WINDOW(level_1_1_window), GTK_WIN_POS_CENTER);

  level_2_1_container = gtk_stack_new();
  gtk_container_add(GTK_CONTAINER(level_1_1_window), level_2_1_container);
  gtk_stack_set_transition_type(GTK_STACK(level_2_1_container), GTK_STACK_TRANSITION_TYPE_CROSSFADE);
  gtk_stack_set_transition_duration(GTK_STACK(level_2_1_container), 500);

  load_scene_1(GTK_WINDOW(level_1_1_window), GTK_STACK(level_2_1_container));

  gtk_widget_show_all(level_1_1_window);
}

int main (int argc, char **argv){
  GtkApplication * application;
  
  application = gtk_application_new("crosses.and.circles._1", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(application, "activate", G_CALLBACK(activate), NULL);
  return g_application_run(G_APPLICATION(application), argc, argv);
}