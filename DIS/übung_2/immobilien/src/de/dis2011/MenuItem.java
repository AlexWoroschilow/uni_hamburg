package de.dis2011;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.function.Function;

public class MenuItem implements MenuInterface {
    private int code;
    private String title;
    private Function<Object, Object> lambda;

    public MenuItem(String title, Function<Object, Object> lambda) {
        this.title = title;
        this.lambda = lambda;
    }

    public void setCode(int code) {
        this.code = code;
    }

    public int getCode() {
        return this.code;
    }

    public Function<Object, Object> getLambda() {
        return this.lambda;
    }

    public String toString() {
        return this.title;
    }

}
