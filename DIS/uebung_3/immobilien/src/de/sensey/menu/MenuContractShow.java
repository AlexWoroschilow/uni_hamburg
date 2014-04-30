package de.sensey.menu;

import de.sensey.service.EntityManager;
import de.sensey.data.Purchase;
import de.sensey.data.Tenancy;

import java.util.ArrayList;

/**
 * Created by studi on 30.04.14.
 */
public class MenuContractShow extends Menu {

    public MenuContractShow(String title) {
        super(title);
        final ArrayList<Purchase> collectionPurchase = (new EntityManager()).getContractsPurchase();
        if (!collectionPurchase.isEmpty()) {
            for (int i = 0; i < collectionPurchase.size(); ++i) {
                Purchase contractPurchase = collectionPurchase.get(i);
                this.addEntry("Purchase: " + contractPurchase, (item) -> {
                    return false;
                });
            }
        }
        final ArrayList<Tenancy> collectionTenancy = (new EntityManager()).getContractsTenancy();
        if (!collectionTenancy.isEmpty()) {
            for (int i = 0; i < collectionTenancy.size(); ++i) {
                Tenancy contractTenancy = collectionTenancy.get(i);
                this.addEntry("Tenancy: " + contractTenancy, (item) -> {
                    return false;
                });
            }
        }
        this.addEntry("Previous menu", (item) -> {
            return false;
        });
    }

}
