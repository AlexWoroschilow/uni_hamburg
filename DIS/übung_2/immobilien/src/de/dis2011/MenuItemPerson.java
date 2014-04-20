package de.dis2011;

import de.dis2011.data.Person;

import java.util.function.Function;

public class MenuItemPerson implements MenuInterface {
    private int code;
    private String title;
    private Function<Object, Object> lambda;

    public MenuItemPerson(String title, Function<Object, Object> lambda) {
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
