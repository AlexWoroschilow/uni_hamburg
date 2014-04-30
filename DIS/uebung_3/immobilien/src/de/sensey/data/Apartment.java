package de.sensey.data;

public class Apartment {
    private int id;
    private int floor;
    private String zip;
    private String city;
    private String street;
    private String street_no;
    private String square;
    private float rent;
    private int room_count;
    private int is_balcony;
    private int is_kitchen;
    private Agent agent;
    private Tenancy contract;

    public Tenancy getContract() {
        return contract;
    }

    public Apartment setContract(Tenancy contract) {
        this.contract = contract;
        return this;
    }

    public Agent getAgent() {
        return agent;
    }

    public Apartment setAgent(Agent agent) {
        this.agent = agent;
        return this;
    }

    /**
     * @return
     */
    public int getId() {
        return id;
    }

    /**
     * @param id
     * @return
     */
    public Apartment setId(int id) {
        this.id = id;
        return this;
    }

    /**
     * @return
     */
    public int getFloor() {
        return this.floor;
    }

    /**
     * @param floor
     * @return
     */
    public Apartment setFloor(int floor) {
        this.floor = floor;
        return this;
    }

    /**
     * @return
     */
    public String getZip() {
        return this.zip;
    }

    /**
     * @param zip
     * @return
     */
    public Apartment setZip(String zip) {
        this.zip = zip;
        return this;
    }

    /**
     * @return
     */
    public String getCity() {
        return this.city;
    }

    /**
     * @param city
     * @return
     */
    public Apartment setCity(String city) {
        this.city = city;
        return this;
    }

    /**
     * @return
     */
    public String getStreet() {
        return this.street;
    }

    /**
     * @param street
     * @return
     */
    public Apartment setStreet(String street) {
        this.street = street;
        return this;
    }

    /**
     * @return
     */
    public String getStreet_no() {
        return this.street_no;
    }

    /**
     * @param streetNo
     * @return
     */
    public Apartment setStreet_no(String streetNo) {
        this.street_no = streetNo;
        return this;
    }

    /**
     * @return
     */
    public String getSquare() {
        return square;
    }

    /**
     * @param square
     */
    public Apartment setSquare(String square) {
        this.square = square;
        return this;
    }

    /**
     * @return
     */
    public float getRent() {
        return this.rent;
    }

    /**
     * @param rent
     * @return
     */
    public Apartment setRent(float rent) {
        this.rent = rent;
        return this;
    }

    /**
     * @return
     */
    public int getRoom_count() {
        return this.room_count;
    }


    /**
     * @param roomCount
     * @return
     */
    public Apartment setRoom_count(int roomCount) {
        this.room_count = roomCount;
        return this;
    }

    /**
     * @return
     */
    public int getIs_balcony() {
        return this.is_balcony;
    }

    /**
     * @param isBalcony
     * @return
     */
    public Apartment setIs_balcony(int isBalcony) {
        this.is_balcony = isBalcony;
        return this;
    }

    /**
     * @return
     */
    public int getIs_kitchen() {
        return this.is_kitchen;
    }

    /**
     * @param isKitchen
     * @return
     */
    public Apartment setIs_kitchen(int isKitchen) {
        this.is_kitchen = isKitchen;
        return this;
    }


    public String toString() {
        return new String(
                "\t\t Zip: " +
                        this.getZip() +
                        "\n\t\t\t City: " +
                        this.getCity() +
                        "\n\t\t\t Street: " +
                        this.getStreet() +
                        "\n\t\t\t Street No: " +
                        this.getStreet_no() +
                        "\n\t\t\t Floor: " +
                        this.getFloor() +
                        "\n\t\t\t Has kitchen: " +
                        this.getIs_kitchen() +
                        "\n\t\t\t Has balcon: " +
                        this.getIs_balcony()
        );
    }
}
