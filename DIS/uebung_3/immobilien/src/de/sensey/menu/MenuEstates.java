package de.sensey.menu;

/**
 * Created by studi on 30.04.14.
 */
public class MenuEstates extends Menu {

    public MenuEstates(String title) {
        super(title);

        this.addEntry("Create estate", (item) -> {
            return (Boolean) this.onCreateEstate(item);
        }).addEntry("Modify estate", (item) -> {
            return (Boolean) this.onEditEstate(item);
        }).addEntry("Delete estate", (item) -> {
            return (Boolean) this.onDeleteEstate(item);
        }).addEntry("Previous menu", (item) -> {
            return false;
        });
    }

    /**
     * @param item
     * @return
     */
    protected Object onCreateEstate(Object item) {
        MenuEstateCreate menu = new MenuEstateCreate(
                "Main menu >> Manage estates >> Create estate"
        );
        while ((Boolean) menu.process()) ;
        return true;
    }

    /**
     * @param item
     * @return
     */
    protected Object onEditEstate(Object item) {
        MenuEstateEdit menu = new MenuEstateEdit(
                "Main menu >> Manage estates >> Edit estate"
        );
        while ((Boolean) menu.process()) ;
        return true;
    }

    /**
     * @param item
     * @return
     */
    protected Object onDeleteEstate(Object item) {
        MenuEstateDelete menu = new MenuEstateDelete(
                "Main menu >> Manage estates >> Delete estate"
        );
        while ((Boolean) menu.process()) ;
        return true;
    }


}
