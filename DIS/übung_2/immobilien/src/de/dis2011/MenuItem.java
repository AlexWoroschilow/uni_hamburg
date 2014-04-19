package de.dis2011;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class MenuItem {
    private int code;
    private String title;
    private Runnable lambda;
    private boolean isContinue;

    public MenuItem(String title, Runnable lambda) {
        this.isContinue = true;
        this.title = title;
        this.lambda = lambda;
    }

    public MenuItem(String title, Runnable lambda, boolean isContinue) {
        this.isContinue = isContinue;
        this.title = title;
        this.lambda = lambda;
    }

    public void setCode(int code) {
        this.code = code;
    }

    public int getCode() {
        return this.code;
    }

    public boolean getIsContinue() {
        return this.isContinue;
    }

    public Runnable getLambda() {
        return this.lambda;
    }

    public String toString() {
        return this.title;
    }

}
