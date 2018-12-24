#include <tracer/ppm.h>
#include <fstream>
#include <cmath>

frey::ppm::ppm(uint h, uint w):
    height(h), width(w)
{
    pixels = std::make_unique<frey::vector>(width * height);
    samples = std::make_unique<uint>(width * height);
    current = std::make_unique<frey::vector>(width * height);
}

void 
frey::ppm::save(std::string filename)
{
    std::ofstream file;    
    file.open(filename.c_str(), std::ofstream::out);

    //PPM header: P3 => RGB, width, height and max RGB value
    file << "P3 " << width << " " << height << " " << 255 << std::endl;

    //lambdas are too cool
    auto to_color = [](double x){
        auto temp = std::pow(x, 1/2.2f) * 255;
        return std::fmin(temp, 255);
    };

    for(int i=0; i<width*height; i++) {
        auto p = pixels.get()[i]/samples.get()[i];
        uint r = to_color(p.getx()), g = to_color(p.gety()), b = to_color(p.getz());
        file << r << " " << g << " " << b << std::endl;
    }

    file.close();
}

void 
frey::ppm::set(uint x, uint y, const frey::vector val)
{
    uint index = (height - y - 1) * width + x; 
    pixels.get()[index] += val;
    samples.get()[index] += 1;
    current.get()[index] = pixels.get()[index]/samples.get()[index];
}

frey::vector 
frey::ppm::get(uint x, uint y)
{
    uint index = (height - y - 1) * width + x;
    return current.get()[index];
}
