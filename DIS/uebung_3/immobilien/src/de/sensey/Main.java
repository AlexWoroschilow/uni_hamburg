package de.sensey;

import de.sensey.menu.MenuMain;

public class Main {

    public static void main(String[] args) {
        while ((Boolean) (new MenuMain("Main menu")).process()) ;
    }
}
