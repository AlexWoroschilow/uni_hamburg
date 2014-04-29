package de.dis2011;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.invoke.LambdaConversionException;
import java.util.ArrayList;
import java.util.function.Function;

/**
 * Kleine Helferklasse für Menüs
 * Zuvor müssen mit addEntry Menüoptionen hinzugefügt werden. Mit
 * der Methode show() wird das Menü angezeigt und die mit der Option
 * angegebene Konstante zurückgeliefert.
 * <p>
 * Beispiel:
 * Menu m = new Menu("Hauptmenü");
 * m.addEntry("Hart arbeiten", 0);
 * m.addEntry("Ausruhen", 1);
 * m.addEntry("Nach Hause gehen", 2);
 * int wahl = m.show();
 * <p>
 * Angezeigt wird dann das Menü:
 * Hauptmenü:
 * [1] Hart arbeiten
 * [2] Ausruhen
 * [3] Nach Hause gehen
 * --
 */
public class Menu {
    protected String title;
    protected ArrayList<String> labels = new ArrayList<String>();
    protected ArrayList<Integer> returnValues = new ArrayList<Integer>();

    protected ArrayList<MenuInterface> items = new ArrayList<MenuInterface>();

    /**
     * Konstruktor.
     *
     * @param title Titel des Menüs z.B. "Hauptmenü"
     */
    public Menu(String title) {
        super();
        this.title = title;
    }

    public Menu addEntry(String label, Function<Object, Object> lambda) {
        this.items.add(new MenuItem(label, lambda));
        return this;
    }

    public Menu addMenuItem(MenuInterface item) {
        this.items.add(item);
        return this;
    }


    public Object process() {
        int selection = 0;

        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

        while (selection == 0) {
            System.out.println(this.title + ":");

            for (int i = 0; i < this.items.size(); ++i) {
                MenuInterface item = this.items.get(i);
                item.setCode(i);
                System.out.println("[" + i + "] " + item.toString());
            }

            System.out.print("-- ");

            try {
                selection = Integer.parseInt(stdin.readLine());
            } catch (NumberFormatException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

            for (int i = 0; i < this.items.size(); ++i) {
                MenuInterface item = this.items.get(i);
                if (selection == item.getCode()) {
                    return item.getLambda().apply(item);
                }
            }

            if (selection < 1 || selection > returnValues.size()) {
                System.err.println("Ungültige Eingabe!");
                selection = 0;
            }
        }

        return false;
    }

    /**
     * Zeigt das Menü an
     *
     * @return Die Konstante des ausgewählten Menüeintrags
     */
    public int show() {
        int selection = -1;

        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

        while (selection == -1) {
            System.out.println(title + ":");

            for (int i = 0; i < labels.size(); ++i) {
                System.out.println("[" + (i + 1) + "] " + labels.get(i));
            }

            System.out.print("-- ");
            try {
                selection = Integer.parseInt(stdin.readLine());
            } catch (NumberFormatException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

            if (selection < 1 || selection > returnValues.size()) {
                System.err.println("Ungültige Eingabe!");
                selection = -1;
            }
        }

        return returnValues.get(selection - 1);
    }
}
