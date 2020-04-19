//
// Created by mtdp on 2020-04-11.
//

#ifndef NATIVEACTIVITYDEMO_OBJHELPER_H
#define NATIVEACTIVITYDEMO_OBJHELPER_H

#include <cstdio>
#include <vector>

class ObjHelper {
public:
    class ObjModel {
    public:
        std::vector<float> vertices; // 3个为一组
        std::vector<float> normals; // 3个为一组
        std::vector<float> texCoords; // 2个为一组
        std::vector<short> indeces; // v vt vn的索引
        ObjModel() {
            vertices.push_back(0); // obj文件中，索引是从1开始的，这里先存入索引0的无用数据。
            vertices.push_back(0);
            vertices.push_back(0);

            normals.push_back(0);
            normals.push_back(0);
            normals.push_back(0);

            texCoords.push_back(0);
            texCoords.push_back(0);
        }
    };
    static void readObjFile(FILE *file, ObjModel *pObjModel);
};

#endif //NATIVEACTIVITYDEMO_OBJHELPER_H
