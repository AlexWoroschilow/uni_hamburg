package de.sensey.menu.item;

import java.util.function.Function;

public class MenuItemHouse implements MenuItemInterface {
    private int code;
    private String title;
    private Function<Object, Object> lambda;

    public MenuItemHouse(String title, Function<Object, Object> lambda) {
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
