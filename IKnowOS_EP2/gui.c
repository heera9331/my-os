#include <gtk/gtk.h>
#include "gui.h"

// Function to close the application
void on_window_closed(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

// Implementation of desktop function
void desktop()
{
    GtkWidget *window;
    GtkWidget *label;

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "New App");
    gtk_container_set_border_width(GTK_CONTAINER(window), 100);
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_closed), NULL);

    // Create a label
    label = gtk_label_new("Hello, World!");

    // Add the label to the window
    gtk_container_add(GTK_CONTAINER(window), label);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}

// Implement any other functions or variables defined in gui.h
