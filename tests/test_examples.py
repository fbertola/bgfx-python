from examples.cubes.cubes import Cubes
from examples.helloworld.helloworld import HelloWorld
from examples.mesh.mesh import MeshExample

from tests.osmesa_context import OSMesaContext


# This test suite use OSMesa to perform rendering on devices that does not
# have a GPU. Paired with XVFB, this will allow to test the library
# loading and the basic rendering calls.


def test_helloworld_example():
    HelloWorld.__bases__ = (OSMesaContext,)
    test = HelloWorld(1280, 720, "Test")
    test.run()
    test.shutdown()


def test_cubes_example():
    Cubes.__bases__ = (OSMesaContext,)
    test = Cubes(1280, 720, "Test")
    test.run()
    test.shutdown()


def test_mesh_example():
    MeshExample.__bases__ = (OSMesaContext,)
    test = MeshExample(1280, 720, "Test")
    test.run()
    test.shutdown()
