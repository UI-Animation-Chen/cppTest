#include <cstdio>
#include "ObjHelper.h"

int main(int argc, const char *argv[], const char *env[]) {
    FILE *file = fopen("./cone.obj", "r");
    auto coneModel = new ObjHelper::ObjModel();
    ObjHelper::readObjFile(file, coneModel);
    fclose(file);

    for (float value: coneModel->vertices)
        printf("%ff,", value);

    printf("count: %d\n", coneModel->indeces.size());
    for (short value: coneModel->indeces)
        printf("%d,", value);

    delete coneModel;
    return 0;
}

