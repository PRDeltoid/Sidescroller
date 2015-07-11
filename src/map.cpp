#include "map.hpp"

Map::Map(string tileset_json, string map_config, string map_bmp) :
    map_config_(new JSONDoc(map_config)),
    map_bmp_(new bitmap_image(map_bmp))
{
    parse(tileset_json);
}

Map::~Map() {
}

void Map::load(string tileset_json) {
    parse(tileset_json);
}

void Map::parse(string tileset_json) {
    //Load the tileset
    int w = map_config_->get("tile_size")["w"].asInt();
    int h = map_config_->get("tile_size")["h"].asInt();
    tileset_.reset(new Tileset(tileset_json, w, h));

    JSONDoc tileset_doc("data/"+tileset_json);
    Json::Value tiletypes = tileset_doc.get("tiletypes");

    //Get tiletypes and their corrisponding map bmp pixel color
    for(unsigned int i=0; i < tiletypes.size(); i++) {
        int red = tiletypes[i]["color"]["red"].asInt();
        int green = tiletypes[i]["color"]["green"].asInt();
        int blue = tiletypes[i]["color"]["blue"].asInt();
        sf::Color color(red, green, blue);
        int numcolor = num_from_color(color);
        int framenum = tiletypes[i]["frame"].asInt();
        tiletypes_[numcolor] = framenum;
    }

    //Go through map bmp, setting map_tiles to the corrisponding tiletype for the pixel color
    unsigned int height = map_bmp_->height();
    unsigned int width = map_bmp_->width();
    for(std::size_t x = 0; x < width; x++) {
        for(std::size_t y = 0; y < height; y++) {
            sf::Color bmp_color = get_tile_color(x, y);
            int numcolor = num_from_color(bmp_color);

            //If color is black, use -1 so the map_tile returns NULL and doesn't render anything
            if(numcolor == 0) {
                map_tiles[x][y] = -1;
                continue;
            }

            map_tiles[x][y] = tiletypes_[numcolor];
        }
    }
}

//Temporary localized draw function (currently draws top 30x30 grid of map)
void Map::draw(boost::shared_ptr<Graphics> graphics) {
    for(std::size_t x = 0; x < 30; x++) {
        for(std::size_t y = 0; y < 30; y++) {
            sf::RectangleShape* rect = tileset_->get_sprite(map_tiles[x][y]);
            //Don't draw blank rects!
            if(rect == NULL) {
                continue;
            }
            //Move the rect to the required position
            rect->setPosition(x*TILE_WIDTH, y*TILE_HEIGHT);
            //Draw the rect
            graphics->draw(rect);
        }
    }
}

sf::Color Map::get_tile_color(int x, int y) {
    unsigned char red,
                  blue,
                  green;
    map_bmp_->get_pixel(x, y, red, green, blue);
    sf::Color color(red, green, blue);
    
    return color;
}


uint32_t Map::num_from_color(sf::Color color) { //uint8_t r, uint8_t b, uint8_t y) {
    uint8_t r, b, g;
    r = color.r;
    g = color.g;
    b = color.b;
    uint32_t single_num = r + (g << 8) + (b << 16);

    return single_num;
}
