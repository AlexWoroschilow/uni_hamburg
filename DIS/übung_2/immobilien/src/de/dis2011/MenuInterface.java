package de.dis2011;

import java.util.function.Function;

public interface MenuInterface {

    public void setCode(int code);

    public int getCode();

    public String toString();

    public Function<Object, Object> getLambda();

}
