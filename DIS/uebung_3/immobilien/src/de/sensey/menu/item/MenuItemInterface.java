package de.sensey.menu.item;

import java.util.function.Function;

public interface MenuItemInterface {

    public void setCode(int code);

    public int getCode();

    public String toString();

    public Function<Object, Object> getLambda();

}
