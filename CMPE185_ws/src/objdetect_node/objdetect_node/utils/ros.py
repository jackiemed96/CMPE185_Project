import rclpy
import torch
from std_msgs.msg import Header
from sensor_msgs.msg import Image
from vision_msgs.msg import Detection2DArray, Detection2D, BoundingBox2D, \
    ObjectHypothesisWithPose
from geometry_msgs.msg import Pose2D
from rclpy.node import Node


def create_header(node: Node):
    h = Header()
    
    h.stamp = node.get_clock().now().to_msg()
    return h


def create_detection_msg(node: Node, img_msg: Image, detections: torch.Tensor) -> Detection2DArray:
    """
    :param img_msg: original ros image message
    :param detections: torch tensor of shape [num_boxes, 6] where each element is
        [x1, y1, x2, y2, confidence, class_id]
    :returns: detections as a ros message of type Detection2DArray
    """
    detection_array_msg = Detection2DArray()

    # header
    header = create_header(node)
    detection_array_msg.header = header
    for detection in detections:
        x1, y1, x2, y2, conf, cls = detection.tolist()
        single_detection_msg = Detection2D()
        single_detection_msg.header = header

        # src img
        #single_detection_msg.source_img= img_msg

        # bbox
        bbox = BoundingBox2D()
        w = float(round(x2 - x1))
        h = float(round(y2 - y1))
        cx = float(round(x1 + w / 2))
        cy = float(round(y1 + h / 2))
        bbox.size_x = w
        bbox.size_y = h

        bbox.center = Pose2D()
        bbox.center.x = cx
        bbox.center.y = cy

        single_detection_msg.bbox = bbox

        # class id & confidence
        obj_hyp = ObjectHypothesisWithPose()
        obj_hyp.hypothesis.class_id = str(cls)
        obj_hyp.hypothesis.score = conf
        single_detection_msg.results = [obj_hyp]

        detection_array_msg.detections.append(single_detection_msg)

    return detection_array_msg