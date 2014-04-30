package de.sensey;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Locale;

/**
 * Kleine Helferklasse zum Einlesen von Formulardaten
 */
public class FormUtil {
    /**
     * Liest einen String vom standard input ein
     *
     * @param label Zeile, die vor der Eingabe gezeigt wird
     * @return eingelesene Zeile
     */
    public static String readString(String label) {
        String ret = null;
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

        try {
            System.out.print(label + ": ");
            ret = stdin.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return ret;
    }

    /**
     * Liest einen Integer vom standard input ein
     *
     * @param label Zeile, die vor der Eingabe gezeigt wird
     * @return eingelesener Integer
     */
    public static int readInt(String label) {
        int ret = 0;
        boolean finished = false;

        while (!finished) {

            try {
                String line = readString(label);
                ret = Integer.parseInt(line);
                finished = true;
            } catch (NumberFormatException e) {
                System.err.println("Ungültige Eingabe: Bitte geben Sie eine Zahl an!");
            }
        }

        return ret;
    }

    public static float readFloat(String label) {
        float ret = 0;
        boolean finished = false;

        while (!finished) {

            try {
                String line = readString(label);
                ret = Float.parseFloat(line);
                finished = true;
            } catch (NumberFormatException e) {
                System.err.println("Ungültige Eingabe: Bitte geben Sie eine Zahl an!");
            }
        }

        return ret;
    }

    public static boolean readBoolean(String label) {
        boolean ret = false;
        boolean finished = false;

        while (!finished) {

            try {
                String line = readString(label);
                ret = Boolean.parseBoolean(line);
                finished = true;
            } catch (NumberFormatException e) {
                System.err.println("Ungültige Eingabe: Bitte geben Sie eine Zahl an!");
            }
        }

        return ret;
    }

    public static Date readDate(String label) {
        Date ret = null;
        boolean finished = false;

        while (!finished) {

            try {
                String line = readString(label);
                ret = new SimpleDateFormat("MMMM d, yyyy", Locale.ENGLISH).parse(line);
                finished = true;
            } catch (NumberFormatException e) {
                System.err.println("Ungültige Eingabe: Bitte geben Sie eine Zahl an!");
            } catch (ParseException e) {
                e.printStackTrace();
            }
        }

        return ret;
    }
}
