#include <gtk/gtk.h>
#include <stdio.h>

static void 
end(GtkWidget *widget,
             gpointer   data,GtkWidget *win){
            exit(-1);
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *frame;
  GtkWidget *box;
  GtkWidget *grid;
  GtkWidget *infolabel;
  GtkWidget *logo;
  GdkPixbuf *pb;
  GtkWidget *label2;
  GtkWidget *exit_button;

  const char * text="Website";
  const char *format = "<a href ='https://linux.tcetmumbai.in//' title='Check out our website!'><b>%s</b></a>";
  char *markup;

  const char *info = "TCET - Linux \n\n1.0\n\nTCET Linux is GNU/Linux distribution, based on Arch Linux built for enhancing college infrastructure and promoting Linux in software engineering education\n\n\n ©2020-2024 TCET-Opensource";

  window = gtk_application_window_new(app);
  box = gtk_box_new (GTK_ORIENTATION_VERTICAL,10);

  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 100);
  gtk_window_set_resizable(GTK_WINDOW(window),false);
 
  button = gtk_button_new_with_label ("Hello World");
  
  frame  = gtk_frame_new ("frame!!!!");
  gtk_widget_set_margin_top(frame,10);
  gtk_widget_set_margin_start(frame,10);
  gtk_widget_set_margin_bottom(frame,10);
  gtk_widget_set_margin_end(frame,10);

  
  grid = gtk_grid_new();
  gtk_grid_set_column_spacing(grid,10);
  gtk_grid_set_row_spacing(grid,10);

  infolabel = gtk_label_new(info);
  gtk_label_set_wrap(infolabel,true);
  gtk_label_set_justify(infolabel,GTK_JUSTIFY_CENTER);
  gtk_label_set_max_width_chars(infolabel,50);
  gtk_widget_set_margin_start(infolabel,10);
  gtk_widget_set_margin_end(infolabel,10);
  gtk_widget_set_hexpand(infolabel,true);
  gtk_widget_set_margin_top(infolabel,5);

  // pb = gdk_pixbuf_new_from_file("a.png", NULL);
  // // pb = gdk_pixbuf_scale_simple(pb,,45,GDK_INTERP_BILINEAR);
  // logo = gtk_picture_new_for_pixbuf(pb);
  // // logo=gtk_image_new_from_file("./a.png");

  logo = gtk_picture_new_for_file(g_file_new_for_path("./a.png"));
  label2 = gtk_label_new(NULL);
  
  markup = g_markup_printf_escaped (format, text);
  gtk_label_set_markup (GTK_LABEL (label2), markup);
  g_free (markup);
  gtk_label_set_wrap(label2,true);
  gtk_label_set_max_width_chars(label2,48);
  gtk_label_set_justify(label2,GTK_JUSTIFY_CENTER);

  exit_button = gtk_button_new_with_label("Back");
  g_signal_connect (exit_button, "clicked",G_CALLBACK(end), NULL);
  gtk_grid_attach(grid,exit_button, 2, 10, 2, 1);
  gtk_grid_attach(grid,infolabel, 0, 2, 4, 2);
  gtk_grid_attach(grid,label2,   0,3, 5, 2);
  gtk_grid_attach(grid , logo , 0, 0, 4, 1);

  gtk_frame_set_child(frame,grid);
 
  
  gtk_window_set_child (GTK_WINDOW (window),frame);




  gtk_window_present (GTK_WINDOW (window));
}


int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
