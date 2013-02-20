void camera_key_press(int key, int x, int y);
class Camera {
    public:
        Camera();
        ~Camera();
        void look_at();
        void camera_key_press(int key, int x, int y);
    private:
        float camera_x, camera_y, camera_z;
        float direction_x, direction_y, direction_z;
        float angle;
};

